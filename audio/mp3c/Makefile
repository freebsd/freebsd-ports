# Created by: Joris Vandalon <joris@vandalon.nl>
# $FreeBSD$

PORTNAME=	mp3c
PORTVERSION=	0.31
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.wspse.de/linux/wspse/

MAINTAINER=	joris@vandalon.nl
COMMENT=	CD to mp3c converter with a console frontend

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	mp3info:audio/mp3info \
		cdrecord:sysutils/cdrtools

USES=		ncurses
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000031
DEFAULT_CDROM_DEVICE=	cd0
.else
DEFAULT_CDROM_DEVICE=	acd0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|rcd0d|${DEFAULT_CDROM_DEVICE}|g' \
		-e 's|/dev/cdrom|/dev/${DEFAULT_CDROM_DEVICE}|g' \
		${WRKSRC}/src/conf.c

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/cdrip.sh ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.post.mk>
