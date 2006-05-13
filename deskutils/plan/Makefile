# New ports collection makefile for:	plan
# Date created:				14 April 1996
# Whom:	Daniel Eischen <deischen@freebsd.org>
#
# $FreeBSD$
#
# Also update	ports/japanese/plan/ (ja-plan) when this port is updated

PORTNAME=	plan
PORTVERSION=	1.9
CATEGORIES+=	deskutils
MASTER_SITES=	ftp://plan.ftp.fu-berlin.de/
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	shaun@inerd.com
COMMENT=	An X/Motif schedule planner with calendar

USE_MOTIF=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
ALL_TARGET=	freebsd
MAN1=		netplan.1 plan.1
MAN4=		plan.4

MAKE_ENV+=	DATADIR=${DATADIR} EXAMPLESDIR=${EXAMPLESDIR}

do-install:
	@${MKDIR} ${EXAMPLESDIR}

	cd ${WRKSRC} \
	   && ${INSTALL_PROGRAM} plan pland netplan notifier ${PREFIX}/bin		\
	   && ${INSTALL_SCRIPT}  ../misc/Killpland ${PREFIX}/bin			\
	   && ${INSTALL_MAN} ../misc/netplan.1 ../misc/plan.1 ${MAN1PREFIX}/man/man1	\
	   && ${INSTALL_MAN} ../misc/plan.4 ${MAN4PREFIX}/man/man4

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/.. \
	   && ${INSTALL_DATA} misc/plan_cal.ps language/* misc/Mkdoc misc/Mkdoc.nawk	\
	                      misc/BlackWhite misc/Monochrome README			\
	                      ${DOCSDIR}
.endif

	cd ${WRKSRC}/../holiday \
	   && ${INSTALL_DATA}   \
	      holiday_australia holiday_austria holiday_bavarian holiday_belgium		\
	      holiday_canada holiday_combi holiday_czech holiday_denmark holiday_dutch		\
	      holiday_finnish holiday_french holiday_frswiss holiday_german holiday_greek	\
	      holiday_hungary holiday_italy holiday_japan holiday_norway holiday_portugal	\
	      holiday_quebec holiday_slovak holiday_spain holiday_swedish holiday_uk		\
	      holiday_us ${EXAMPLESDIR}

.if !target(post-install)
post-install:
	@${MKDIR} ${DATADIR}/netplan.dir
.endif

.include <bsd.port.mk>
