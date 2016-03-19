# Created by: Daniel Eischen <deischen@FreeBSD.org>
# $FreeBSD$

# Also update	ports/japanese/plan/ (ja-plan) when this port is updated

PORTNAME=	plan
PORTVERSION=	1.10.1
CATEGORIES+=	deskutils
MASTER_SITES=	ftp://plan.ftp.fu-berlin.de/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	X/Motif schedule planner with calendar

USES=		motif
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
ALL_TARGET=	freebsd

MAKE_ENV+=	DATADIR=${DATADIR} EXAMPLESDIR=${EXAMPLESDIR}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

	cd ${WRKSRC} \
	   && ${INSTALL_PROGRAM} plan pland netplan notifier ${STAGEDIR}${PREFIX}/bin		\
	   && ${INSTALL_SCRIPT}  ../misc/Killpland ${STAGEDIR}${PREFIX}/bin			\
	   && ${INSTALL_MAN} ../misc/netplan.1 ../misc/plan.1 ${STAGEDIR}${MAN1PREFIX}/man/man1	\
	   && ${INSTALL_MAN} ../misc/plan.4 ${STAGEDIR}${MAN4PREFIX}/man/man4

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/.. \
	   && ${INSTALL_DATA} misc/plan_cal.ps language/* misc/Mkdoc misc/Mkdoc.nawk	\
	                      misc/BlackWhite misc/Monochrome README			\
	                      ${STAGEDIR}${DOCSDIR}

	cd ${WRKSRC}/../holiday \
	   && ${INSTALL_DATA}   \
	      holiday_australia holiday_austria holiday_bavarian holiday_belgium		\
	      holiday_canada holiday_combi holiday_czech holiday_denmark holiday_dutch		\
	      holiday_finnish holiday_french holiday_frswiss holiday_german holiday_greek	\
	      holiday_hungary holiday_italy holiday_japan holiday_norway holiday_portugal	\
	      holiday_quebec holiday_slovak holiday_spain holiday_swedish holiday_uk		\
	      holiday_us ${STAGEDIR}${EXAMPLESDIR}

.if !target(post-install)
post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/netplan.dir
.endif

.include <bsd.port.mk>
