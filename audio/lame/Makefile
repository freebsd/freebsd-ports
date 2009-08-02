# ports collection makefile for:   lame
# Date created:        11 January 1998
# Whom:                yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	lame
PORTVERSION=	3.98.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.fu-berlin.de/unix/sound/%SUBDIR%/
MASTER_SITE_SUBDIR=	lame
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//:S/./-/}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Fast MP3 encoder kit

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--enable-nasm --enable-mp3rtp --disable-gtktest

RESTRICTED=	patent issues, see http://www.mp3licensing.com/

MAN1=		lame.1

DOC_FILES=	API LICENSE README TODO USAGE

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

post-patch:
# Fix parallel builds
	@${REINPLACE_CMD} -e 's,test -d \.libs || mkdir,mkdir -p,' \
		${WRKSRC}/libmp3lame/i386/Makefile.in

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

.include <bsd.port.post.mk>
