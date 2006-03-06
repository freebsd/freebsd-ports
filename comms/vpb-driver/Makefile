# New ports collection makefile for:	vpb-driver
# Date created:				11 Feb 2005
# Whom:					Chris Forkin <chris@forkin.com>
#
# $FreeBSD$
#

PORTNAME=	vpb-driver
PORTVERSION=	2.4.9
CATEGORIES=	comms
MASTER_SITES=	http://www.voicetronix.com/Downloads/

MAINTAINER=	chris@forkin.com
COMMENT=	Device-driver for the Voicetronix OpenLine4 PCI telephony cards

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	vpb.sh
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
MAKE_ENV+=	KMODDIR=${PREFIX}/lib

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%DATADIR%%,${DATADIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \

.include <bsd.port.pre.mk>

BROKEN=		Incomplete pkg-plist

.if !exists(/usr/src/sys)
IGNORE=		requires kernel source (/usr/src/sys) to build
.endif

.if ${OSVERSION} < 502000 || ${OSVERSION} >= 600000
IGNORE=		is not for FreeBSD versions < 502000, or >= 600000
.endif

do-configure:
	@${REINPLACE_CMD} -E ${SED_SCRIPT} ${WRKSRC}/src/vpbreg.cpp

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
