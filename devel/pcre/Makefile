# New ports collection makefile for:	pcre
# Date created:				08 July 1998
# Whom:					dom
#
# $FreeBSD$
#

PORTNAME=	pcre
PORTVERSION=	3.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dom@happygiraffe.net

# Disabled until SourceForge put a proper copy of .tar.bz2 file on its mirrors
# Currently, it is corrupted and does not match the one on the master site:
#     ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/
#
# USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		pcregrep.1 pcretest.1
MAN3=		pcre.3 pcreposix.3

.include <bsd.port.mk>
