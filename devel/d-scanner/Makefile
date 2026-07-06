PORTNAME=	d-scanner
PORTVERSION=	0.15.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Swiss-army knife for D source code
WWW=		https://github.com/dlang-community/D-Scanner

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		rdmd:lang/dlang-tools

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	dlang-community
GH_PROJECT=	D-Scanner
GH_TUPLE=	dlang-community:DCD:1c60c54:DCD/DCD \
		dlang-community:containers:116a028:containers/containers \
		burner:inifiled:cecaff8:inifiled/inifiled \
		dlang-community:libddoc:fbbfb82:libddoc/libddoc \
		dlang-community:libdparse:fe6d1e3:libdparse/libdparse

MAKE_ENV+=	DC=${DC}
MAKEFILE=	makefile

PLIST_FILES=	bin/dscanner
DC=		ldmd2

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dscanner ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
