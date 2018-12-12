# $FreeBSD$

PORTNAME=	kcov
DISTVERSIONPREFIX=	v
DISTVERSION=	36
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Coverage checker for ELF, Bash, and Python programs

LICENSE=	GPLv2 MIT # MIT for bundled handlebars, jquery, tablesorter
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	ptrace code is only implemented for amd64

BUILD_DEPENDS=	binutils>=2.30:devel/binutils
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libdw.so:devel/elfutils \
		libelf.so:devel/elfutils

USES=		cmake:outsource shebangfix python:build gettext-runtime

# Remove -DPORTVERSION (and associated patch) when basing the port on an
# official release
CMAKE_ARGS=	-DKCOV_INSTALL_MANDIR=${PREFIX}/man -DPORTVERSION=${PORTVERSION}

SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	SimonKagstrom

PLIST_FILES=	bin/kcov \
		man/man1/kcov.1.gz

OPTIONS_DEFINE=	DOCS
PORTDOCS=	COPYING.externals \
		ChangeLog

post-stage:
	${RM} ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
