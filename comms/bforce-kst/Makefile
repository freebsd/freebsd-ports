# New ports collection makefile for:	bforce-kst
# Date created:		1 May 2002
# Whom:			Andrew Dolgov <fox@furry.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	bforce
PORTVERSION=	0.22.7.5
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://kst.spb.ru/bforce/
PKGNAMESUFFIX=	-kst
DISTNAME=	bforce-0.22.7.kst5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple ifcico like Fidonet technology mailer

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/source

do-install:
	${MKDIR} ${PREFIX}/etc/bforce
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.conf ${PREFIX}/etc/bforce/bforce.conf.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.passwd ${PREFIX}/etc/bforce/bforce.passwd.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.subst ${PREFIX}/etc/bforce/bforce.subst.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/freq.aliases ${PREFIX}/etc/bforce/freq.aliases.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/freq.dirs ${PREFIX}/etc/bforce/freq.dirs.sample
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bforce ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bfindex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bfstat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nlookup ${PREFIX}/bin

.include <bsd.port.mk>
