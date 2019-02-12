# $FreeBSD$

PORTNAME=	sysctlview
PORTVERSION=	0.1
CATEGORIES=	deskutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Show sysctl mib

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig gettext-runtime gnome
USE_GNOME=	gtk30 pango atk cairo gdkpixbuf2 glib20

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	4f35c02f0c9fa3d27fbfbc4e654272b1c2d7d54d

DESKTOP_ENTRIES="Sysctlview" "Show kernel state" "" \
		"sysctlview" "System;" false

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PLIST_FILES=	bin/sysctlview \
		${DATADIR}/sysctlview.window.xml

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysctlview ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/sysctlview.window.xml ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
