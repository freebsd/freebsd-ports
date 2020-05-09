# $FreeBSD$

PORTNAME=	git-remote-hg
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Transparent bidirectional bridge between Git and Mercurial for Git

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	a2x:textproc/asciidoc
RUN_DEPENDS=	hg:devel/mercurial

USES=		gmake python:2.7 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	mnauw
MAKE_ENV=	prefix="${PREFIX}"
SHEBANG_FILES=	git-remote-hg

INSTALL_TARGET=	install install-doc

PLIST_FILES=	bin/git-remote-hg man/man1/git-remote-hg.1.gz

.include <bsd.port.mk>
