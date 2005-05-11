# New ports collection makefile for:    jc
# Date created:         		20 Feb 2004
# Whom:                 		Archie Cobbs <archie@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	jc
PORTVERSION=	1.4.4
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=jcvm/

MAINTAINER=	archie@freebsd.org
COMMENT=	JVM that converts class files to C source and compiles them with GCC

BUILD_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:${PORTSDIR}/java/classpath
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

MAN1=		jc.1

USE_LIBTOOL_VER=15
USE_JAVA=	yes
USE_GMAKE=	yes
JAVA_BUILD=	jre
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-classpath=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
INFO=		jc
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

post-install:
.for dir in ${PREFIX}/include/jc ${PREFIX}/lib/jc ${PREFIX}/share/jc
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@if [ -f ${PREFIX}/lib/libjc.a ]; then \
		${ECHO} lib/libjc.a >> ${TMPPLIST}; \
	fi
.endfor

.include <bsd.port.post.mk>
