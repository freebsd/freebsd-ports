# New ports collection makefile for: 	fhist
# Version required: 			1.1
# Date created:    			Apr 23 1998
# Whom: 				<koshy@india.hp.com>
#
# $FreeBSD$
#

DISTNAME=	fhist.1.1
PKGNAME=	fhist-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://archie.au/unix/Aegis/			\
		http://www.canb.auug.org.au/~millerp/		\
		ftp://ftp.agso.gov.au/pub/Aegis/ 		\
		ftp://ftp.u-aizu.ac.jp/pub/misc/tools/Aegis/	\
		http://gd.tuwien.ac.at/softeng/Aegis/

MAINTAINER=	koshy@india.hp.com

MAN1=		fcomp.1 fhist.1 fmerge.1

GNU_CONFIGURE=	yes

post-install:
.for file in fhist fcomp fmerge
	strip ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
