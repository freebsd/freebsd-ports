# New ports collection makefile for:	DrScheme
# Date created:		21 Jun 2001
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drscheme
PORTVERSION=	202
CATEGORIES=	lang
MASTER_SITES=	http://download.plt-scheme.org/bundles/${PORTVERSION}/plt/ \
		http://www.cs.utah.edu/plt/download/${PORTVERSION}/plt/ \
		ftp://ftp.pasteur.fr/pub/computing/Scheme/plt-scheme/${PORTVERSION}/plt/ \
		ftp://archive.informatik.uni-tuebingen.de/unix/language/plt/${PORTVERSION}/plt/ \
		ftp://morpheus.wish.com.mx/pub/plt/${PORTVERSION}/plt/
DISTNAME=	plt.src.x

MAINTAINER=	jkoshy@freebsd.org

DIST_SUBDIR=	drscheme/${PORTVERSION}
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/plt/src
ALL_TARGET=	all install
USE_XLIB=	yes

PLTHOME=	${PREFIX}/drscheme
DRS_D=		bin install collects teachpack
DRS_B=		drscheme mred mzc mzscheme tex2page
MAN1=		drscheme.1 mred.1 mzscheme.1

do-install:
	${MKDIR} ${PLTHOME}
	cd ${WRKDIR}/plt && ${TAR} -cf - ${DRS_D} | tar -C ${PLTHOME} -xf -
	cd ${PLTHOME} && ${PLTHOME}/install
.for f in ${DRS_B}
	${LN} -s ${PLTHOME}/bin/$f ${PREFIX}/bin/$f
.endfor
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKDIR}/plt/man/man1/$f ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
