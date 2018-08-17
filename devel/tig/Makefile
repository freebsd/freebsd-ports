# Created by: Denise H. G. <darcsis@gmail.com>
# $FreeBSD$

PORTNAME=	tig
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jonas/tig/releases/download/${DISTNAME}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Text-mode interface for git

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv gmake ncurses readline:port
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE}
MAKE_ARGS=	V=1

INSTALL_TARGET=	install install-doc-man

PLIST_FILES=	bin/tig \
		etc/tigrc \
		man/man1/tig.1.gz \
		man/man5/tigrc.5.gz \
		man/man7/tigmanual.7.gz

OPTIONS_DEFINE=	GIT

GIT_DESC=	Install devel/git as runtime dependency

GIT_RUN_DEPENDS=	git:devel/git
GIT_VARS_OFF=	PKGMESSAGE="${.CURDIR}/pkg-message-git"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tig

.include <bsd.port.mk>
