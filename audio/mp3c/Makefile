# Created by: Joris Vandalon <joris@vandalon.nl>
# $FreeBSD$

PORTNAME=	mp3c
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.wspse.de/linux/wspse/:src
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:src \
		cdrip.sh
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joris@vandalon.nl
COMMENT=	A CD to mp3c converter with a console frontend

RUN_DEPENDS=	mp3info:${PORTSDIR}/audio/mp3info \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}"

NO_STAGE=	yes
MAN1=		mp3c.1
MANCOMPRESSED=	no

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|rcd0d|acd0|g' ${WRKSRC}/src/conf.c
	@${REINPLACE_CMD} -e 's|/dev/cdrom|/dev/acd0|g' ${WRKSRC}/src/conf.c

post-install:
	${INSTALL_SCRIPT} ${DISTDIR}/cdrip.sh ${LOCALBASE}/bin

.include <bsd.port.mk>
