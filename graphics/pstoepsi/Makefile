# New ports collection makefile for:	pstoepsi
# Date created:		21 Jul 2002
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoepsi
PORTVERSION=	20020711
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.usc.edu/pub/tgif/tools/pstoepsi/
DISTFILES=	pstoepsi README.this-site
DIST_SUBDIR=	pstoepsi
EXTRACT_ONLY=	#empty

MAINTAINER=	mita@FreeBSD.org
COMMENT=	Wiliam Chia-Wei Cheng's yet another PS to EPSI converter

RUN_DEPENDS=	pbmtoepsi:${PORTSDIR}/graphics/netpbm

USE_GHOSTSCRIPT_RUN=	yes
NO_WRKSUBDIR=	yes

.SILENT:

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

pre-patch:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/pstoepsi ${WRKDIR}/pstoepsi.prefix
	${CP} ${DISTDIR}/${DIST_SUBDIR}/README.this-site ${WRKDIR}

do-build:
	${SED} -e "s+%%PREFIX%%+${PREFIX}+g" ${WRKDIR}/pstoepsi.prefix > \
						${WRKDIR}/pstoepsi
	${GZIP_CMD} ${WRKDIR}/README.this-site

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pstoepsi ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/pstoepsi
	${INSTALL_DATA} ${WRKDIR}/README.this-site.gz \
			${PREFIX}/share/doc/pstoepsi

.include <bsd.port.mk>
