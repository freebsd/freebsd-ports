# New ports collection makefile for:	hcfmdm
# Date Created:				Jul 30, 2006
# Whom:					Alexey Illarionov <littlesavage@rambler.ru>
#
# Based on: ltmdm created by Daniel O'Connor <darius@dons.net.au>
# Based on: $FreeBSD$
#
# $FreeBSD$
#

PORTNAME=	hcfmdm
PORTVERSION=	0.99.1
PORTREVISION=	1
CATEGORIES=	comms kld
MASTER_SITES=	http://lug.cbx.ru/files/modem/ \
		http://www.int21.de/conexant/ \
		${MASTER_SITE_GENTOO} \
		http://marvin.lirex.com/~maxx/ \
		http://zoltek7.webpark.pl/ \
		http://www.linuxant.com/drivers/hsf/free/archive/
DISTFILES=	hcfmdm-0.99.1.tar.gz \
		hcfpcimodem-0.99lnxtbeta03042700.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	hcfmdm-0.99.1.tar.gz hcfpcimodem-0.99lnxtbeta03042700.tar.gz

MAINTAINER=	littlesavage@rambler.ru
COMMENT=	Driver for the Conexant HCF PCI winmodem chipset (Acorp PIM/PIM2)

MODULES_WITH_WORLD?=	yes
ONLY_FOR_ARCHS=	i386
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
RESTRICTED=	Redistribution of versions marked lnxtbeta requires explicit written approval from Linuxant
RESTRICTED_FILES=	hcfpcimodem-0.99lnxtbeta03042700.tar.gz
NO_CDROM=	No redistribution allowed
NO_PACKAGE=	${NO_CDROM}

LNXTDOCS=	README FAQ BUGS
PORTDOCS=	${LNXTDOCS} 100498D_RM_HxF_Released.pdf

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600100
IGNORE=	is not for FreeBSD versions < 600100
.endif

.if ${OSVERSION} >= 700000
BROKEN=	Does not compile at 7.x or higher
.endif

PLIST_SUB+=	KMODDIR=${KMODDIR}

.if !defined(NOPORTDOCS)
DISTFILES+=	100498D_RM_HxF_Released.pdf
.endif

pre-fetch:
.if !exists(/usr/src/sys/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO}  "This port requires the kernel source be available"; \
	${ECHO}  "*************************************************"; \
	exit 1
.endif

do-install:
	@${MKDIR} ${KMODDIR}
	@${INSTALL_KLD} ${BUILD_WRKSRC}/hcfmdm.ko ${KMODDIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${LNXTDOCS}
	@${INSTALL_DATA} ${WRKDIR}/hcfpcimodem-0.99lnxtbeta03042700/${i} ${DOCSDIR}/
.endfor

	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/100498D_RM_HxF_Released.pdf ${DOCSDIR}/
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
