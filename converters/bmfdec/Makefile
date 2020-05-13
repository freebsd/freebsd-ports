# $FreeBSD$

PORTNAME=	bmfdec
DISTVERSION=	g20200512
CATEGORIES=	converters devel sysutils

MAINTAINER=	takawata@FreeBSD.org
COMMENT=	Decompile binary MOF file (BMF) from WMI buffer

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	pali
GH_TAGNAME=	7f47b07

PLIST_FILES=	${BINARIES:S,^,bin/&,}

BINARIES=	bmf2mof bmfdec bmfparse

do-install:
	(cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${BINARIES} ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
