# ports collection makefile for:   lame
# Date created:        11 January 1998
# Whom:                yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	lame
PORTVERSION=	3.95.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.fu-berlin.de/unix/sound/%SUBDIR%/
MASTER_SITE_SUBDIR=	lame

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	ISO code based fast MP3 encoder kit

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-nasm --enable-mp3rtp --disable-gtktest

MAN1=		lame.1

DOC_FILES=	API LICENSE PRESETS.draft README TODO USAGE

.if defined(NOPORTDOCS)
do-install:
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-exec
	@cd ${INSTALL_WRKSRC}/include && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-data
	@cd ${INSTALL_WRKSRC}/doc/man && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-data
.else
post-install: install-doc

install-doc:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
