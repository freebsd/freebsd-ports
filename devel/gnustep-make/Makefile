# New ports collection makefile for:    gnustep-make
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-make
PORTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/core/ \
		http://ftp.codefactory.se/pub/gnu/gstep/ \
		http://planetmirror.com/pub/gnustep/core/

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		"Sorry, this port does not work on FreeBSD-2.2.x"
.endif

USE_NEWGCC=	yes
PREFIX=		${LOCALBASE}/GNUstep
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c" \
		CFLAGS="${CFLAGS} -D_THREAD_SAFE"
CONFIGURE_TARGET=
USE_GMAKE=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
NO_MTREE=	yes

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L} VERSION=${PORTVERSION}

post-patch:
.for f in gswapp gswbundle
	${PERL} -pi -e 's/\$$\(TAR\) ch --exclude=CVS --to-stdout/\$$\(TAR\) -ch --exclude=CVS -f -/g' ${WRKSRC}/${f}.make
.endfor

post-configure:
	${SED} -e "s/\(objc_threaded:=\).*/\1 ${PTHREAD_LIBS}/" \
		< ${WRKSRC}/config.make > ${WRKSRC}/config.make.new
	${MV} ${WRKSRC}/config.make.new ${WRKSRC}/config.make

.include <bsd.port.post.mk>
