# New ports collection makefile for:	gawk+mb
# Version required:	2.15.6+mb1.04
# Date created:		5 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.3 1995/04/09 09:01:30 asami Exp $
#

DISTNAME=	gawk-2.15.6
PKGNAME=	jp-gawk-2.15.6
CATEGORIES+=	japanese
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/GNU/

MAINTAINER=	asami@FreeBSD.ORG

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	bsd44
PATCH_STRIP=	-p1

PATCH_SITES=	ftp://ftp.iij.ad.jp/pub/NetNews/fj.sources/volume95/May/
PATCHFILES=	gawk-2.15.6-mb1.04.diff.gz
DISTPATCHES=	950503.01.Z 950503.02.Z 950503.03.Z 950503.04.Z
PATCH_DIST_STRIP=	-p1

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
		sed -e '1,/-----8</d' -e '/-----8</,/-----8</d' | uudecode; \
	    rm -f ${DISTPATCHES};\
	 fi)

.include <bsd.port.mk>
