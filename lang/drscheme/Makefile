# New ports collection makefile for:	DrScheme
# Date created:		21 Jun 2001
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drscheme
PORTVERSION=	103p1
CATEGORIES=	lang
MASTER_SITES= http://www.cs.rice.edu/CS/PLT/packages/download/103p1/plt/ \
	ftp://ftp.pasteur.fr/pub/computing/Scheme/DrScheme/103p1/plt/ \
	ftp://archive.informatik.uni-tuebingen.de/unix/language/plt/103p1/plt/
DISTNAME=	plt.src.x

MAINTAINER=	jkoshy@freebsd.org

HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/plt/src
ALL_TARGET=	all install
USE_XLIB=	yes

PLTHOME=	${PREFIX}/drscheme
DRS_D=		bin .bin install collects teachpack
DRS_B=		drscheme drscheme-jr mred mzc mzscheme
MAN1=		drscheme-jr.1 drscheme.1 mred.1 mzscheme.1

do-install:
	${MKDIR} ${PLTHOME}
	cd ${WRKDIR}/plt && ${TAR} -cf - ${DRS_D} | tar -C ${PLTHOME} -xvf -
	cd ${PLTHOME} && ${PLTHOME}/install
.for f in ${DRS_B}
	${LN} -s ${PLTHOME}/bin/$f ${PREFIX}/bin/$f
.endfor
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKDIR}/plt/man/man1/$f ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
