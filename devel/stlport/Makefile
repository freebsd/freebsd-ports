# ex:ts=8
# Ports collection makefile for:  stlport
# Date Created:			  2 December 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	stlport
PORTVERSION=	4.0
CATEGORIES=	devel
MASTER_SITES=	http://www.stlport.com/archive/  \
		http://www.stlport.com/beta/
DISTNAME=	STLport-${PORTVERSION:S/.b/-b/}

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>

.if !exists(/usr/include/wchar.h)
BROKEN=		"requires /usr/include/wchar.h for compilation"
.endif

WRKSRC=		${WRKDIR}/STLport-${PORTVERSION:S/.b/b/}/src
MAKEFILE=	gcc.mak
ALL_TARGET=	clean all
USE_GMAKE=	yes

FIND?=	/usr/bin/find

.if ${OSVERSION} < 440000
BROKEN=		"Not supported on systems prior to FreeBSD 4.4"
.endif

pre-build:
	@${LN} -sf /usr/include/g++ ${WRKSRC}/../include

post-build:
.for lib in libstlport_gcc.so libstlport_gcc_debug.so libstlport_gcc_stldebug.so
	@${MV} ${WRKSRC}/../lib/${lib} ${WRKSRC}/../lib/${lib}.4_0_${PORTREVISION}
.endfor
	-# get list from `export' files in version 4.1, rather than do this
	@cd ${WRKSRC}/../stlport ; ${RM} -rf BC50 SC5 config/new_compiler old_hp
	@${FIND} ${WRKSRC}/../stlport -name "*.orig" -delete

do-install:
	@cd ${WRKSRC}/.. ; pax -rw stlport ${PREFIX}/include
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/include/stlport
	@${CHMOD} -R ${SHAREMODE} ${PREFIX}/include/stlport
	@${FIND} ${PREFIX}/include/stlport -type d -exec ${CHMOD} 0755 {} \;
	@${INSTALL_DATA} ${WRKSRC}/../lib/* ${PREFIX}/lib
.for lib in libstlport_gcc.so libstlport_gcc_debug.so libstlport_gcc_stldebug.so
	@cd ${PREFIX}/lib ; ${LN} -sf ${lib}.4_0_${PORTREVISION} ${lib}
.endfor
	@${MKDIR} ${PREFIX}/share/doc/html/stlport/images
	@cd ${WRKSRC}/../doc ; ${INSTALL_MAN} *.css *.html ${PREFIX}/share/doc/html/stlport
	@cd ${WRKSRC}/../doc ; ${INSTALL_MAN} images/* ${PREFIX}/share/doc/html/stlport/images

.include <bsd.port.post.mk>
