# New ports collection makefile for:	gxditview (part of ja-groff)
# Version required:	1.09+0.98
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.9 1998/10/09 01:41:11 asami Exp $
#

DISTNAME=	groff-1.09
PKGNAME=	ja-gxditview-0.98
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff

MAINTAINER=	ports@FreeBSD.ORG

PATCH_SITES=	ftp://ftp.iij.ad.jp/pub/NetNews/fj.sources/volume95/Apr/
PATCHFILES=	jgroff-0.98.diff.gz
DISTPATCHES=	950414.01.Z 950414.02.Z
PATCH_DIST_ARGS?=	-d ${WRKSRC}/.. --forward --quiet -E -p1

USE_IMAKE=	yes
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/work/${DISTNAME}/xditview

pre-fetch: 
	@(cd ${DISTDIR}; \
	 if [ ! -f ${PATCHFILES} ]; then \
	    ${ECHO_MSG} ">> ${PATCHFILES} doesn't seem to exist on this system."; \
	    for file in ${DISTPATCHES} ; do \
		for site in ${PATCH_SITES} ; do \
		    if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${file} ${FETCH_AFTER_ARGS}; then \
			break; \
		    fi \
		done; \
	    done; \
	    for file in ${DISTPATCHES} ; do zcat $${file}; done | \
		sed '/^END -----/,/^BEGIN ----/d' | uudecode; \
	    rm -f ${DISTPATCHES};\
	 fi)

.include <bsd.port.mk>
