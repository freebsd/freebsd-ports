# New ports collection makefile for:	vpb-driver
# Date created:				11 Feb 2005
# Whom:					Chris Forkin <chris@forkin.com>
#
# $FreeBSD$
#

PORTNAME=	vpb-driver
PORTVERSION=	2.4.9
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://www.voicetronix.com/Downloads/

MAINTAINER=	chris@forkin.com
COMMENT=	Device-driver for the Voicetronix OpenLine4 PCI telephony cards

USE_GMAKE=	yes
USE_RC_SUBR=	vpb.sh
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
KMODDIR?=	/boot/modules
MAKE_ENV+=	KMODDIR=${KMODDIR}

PLIST_SUB+=	KMODDIR=${KMODDIR}
SUB_LIST+=	KMODDIR=${KMODDIR}

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%DATADIR%%,${DATADIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \

.include <bsd.port.pre.mk>

.if !exists(/usr/src/sys)
IGNORE=		requires kernel source (/usr/src/sys) to build
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=	Does not compile on ${ARCH}
.else
BROKEN=	leaves files behind on deinstall
.endif
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2006-12-01

.if ${OSVERSION} < 502000
IGNORE=		is not for FreeBSD versions < 502000
.endif

do-configure:
	@${REINPLACE_CMD} -E ${SED_SCRIPT} ${WRKSRC}/src/vpbreg.cpp

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
