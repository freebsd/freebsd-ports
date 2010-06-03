# New ports collection makefile for:	gcal
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=		gcal
PORTVERSION=		3.6
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The GNU Gregorian calendar program

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"

INFO=		gcal
#MAN1=		gcal.1 gcal2txt.1 tcal.1 txt2gcal.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

GCAL_SCRIPTS=	daily/daily ddiff/ddiff ddiff/ddiffdrv dst/dst gcalltx/gcalltx \
		gcalltx/gcalltxp moon/moon mrms/mrms srss/srss wloc/wlocdrv

post-patch:
.for p in ${GCAL_SCRIPTS}
	@${REINPLACE_CMD} -e '/^ThisGcal=/s:=.*:=${PREFIX}/bin/gcal:' \
		-e '/^packagedatamiscdir=/s:=.*:=${DATADIR}/misc/${p:H}:' \
		${WRKSRC}/misc/${p}.in
.endfor

post-install:
	@${TAR} -cf - -C ${WRKSRC} --exclude '*.in' --exclude '*.in.bak' \
		--exclude '*.alias' misc | ${TAR} -xpf - -C ${DATADIR}
.for p in ${GCAL_SCRIPTS}
	@${CHMOD} +x ${DATADIR}/misc/${p}
	@${LN} -s ${DATADIR}/misc/${p} ${PREFIX}/bin/gcal-${p:T}
.endfor

.include <bsd.port.mk>
