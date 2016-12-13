# Created by: Denise H. G. <darcsis@gmail.com>
# $FreeBSD$

PORTNAME=	tig
PORTVERSION=	2.2.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jonas/tig/releases/download/${DISTNAME}/

MAINTAINER=	darcsis@gmail.com
COMMENT=	Text-mode interface for git

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	git:devel/git

USES=		iconv gmake ncurses readline:port
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE}
MAKE_ARGS=	V=1

ALL_TARGET=	all strip
INSTALL_TARGET=	install

PLIST_FILES=	bin/tig etc/tigrc

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
MANPAGES_ALL_TARGET=	doc-man
MANPAGES_INSTALL_TARGET=	install-doc-man
MANPAGES_PLIST_FILES=	man/man1/tig.1.gz \
			man/man5/tigrc.5.gz \
			man/man7/tigmanual.7.gz

.include <bsd.port.mk>
