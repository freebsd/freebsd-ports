# New ports collection makefile for:	gxditview (part of jp-groff)
# Version required:	1.09+0.98
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.2 1995/05/02 10:36:33 asami Exp $
#

DISTNAME=	groff-1.09
PKGNAME=	jp-gxditview-0.98
CATEGORIES=	japanese printing
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

MAINTAINER=	asami@FreeBSD.ORG

PATCH_SITES=	ftp://ftp.iij.ad.jp/pub/NetNews/fj.sources/volume95/Apr/
PATCHFILES=	jgroff-0.98.diff.gz
DISTPATCHES=	950414.01.Z 950414.02.Z
PATCH_DIST_ARGS?=	-d ${WRKSRC}/.. --forward --quiet -E -p1

USE_IMAKE=	yes
WRKSRC=${.CURDIR}/work/${DISTNAME}/xditview

pre-fetch: 
	@(cd ${DISTDIR}; \
	 if [ ! -f ${PATCHFILES} ]; then \
	    ${ECHO_MSG} ">> ${PATCHFILES} doesn't seem to exist on this system."; \
	    for file in ${DISTPATCHES} ; do \
		for site in ${PATCH_SITES} ; do \
		    if ${NCFTP} ${NCFTPFLAGS} $${site}$${file}; then \
			break; \
		    fi \
		done; \
	    done; \
	    for file in ${DISTPATCHES} ; do zcat $${file}; done | \
		sed '/^END -----/,/^BEGIN ----/d' | uudecode; \
	    rm -f ${DISTPATCHES};\
	 fi)

.include <bsd.port.mk>
