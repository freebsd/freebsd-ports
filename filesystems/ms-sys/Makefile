PORTNAME=	ms-sys
PORTVERSION=	2.9.0
CATEGORIES=	filesystems
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20development/${PORTVERSION}

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Tool for writing Microsoft compatible boot record
WWW=		https://ms-sys.sourceforge.net/

LICENSE=		GPLv2 EULA
LICENSE_COMB=		multi
LICENSE_NAME_EULA=	The Microsoft End-User License Agreement
LICENSE_TEXT_EULA=	ms-sys binary contains embedded proprietary boot code
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_PERMS_EULA=	auto-accept

USES=		gettext-tools gmake
MAKE_ARGS+=	MANDIR="${PREFIX}/share/man"

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime localbase
NLS_MAKE_ARGS=	LDFLAGS="-L${LOCALBASE}/lib -lintl"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
