# New ports collection makefile for:	NCBI
# Date created:         03 April 2000
# Whom:                 tonym
#
# $FreeBSD$
#

PORTNAME=	ncbi-toolkit
PORTVERSION=	2000.10.31
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/toolbox/ncbi_tools/old/${PORTVERSION:S/.//g}/
DISTNAME=	ncbi
DIST_SUBDIR=	ncbi

MAINTAINER=	tony.maher@ebioinformatics.com

USE_MOTIF=	yes

#
# In the files directory we have:
#

DUMMYMAKE=	Makefile

#
#	out of it for the post-install when we put in system startup file.
#

PLATFORMDIR=	${WRKSRC}/platform
BUILDSCRIPT=	${WRKSRC}/make/makedis.csh

#
# Thus ends the definitions
#

#
# We need a dummy top level Makefile as NCBI has scripts that need to
# run from point above ncbi hierachy.
#

pre-configure:
	@${CP} ${FILESDIR}/${DUMMYMAKE} ${WRKSRC}
	@${CP} ${FILESDIR}/freebsd.ncbi.mk ${PLATFORMDIR}
	@${PERL} -pi.orig -e 's#NetBSD#FreeBSD#;'  -e 's#netbsd#freebsd#' ${BUILDSCRIPT}

.include <bsd.port.mk>
