# New ports collection makefile for:	xa+cv
# Version required:	0.6
# Date created:		29 March 1999
# Whom:			Clive Lin <clive@CirX.ORG>
#
# $FreeBSD: /tmp/pcvs/ports/chinese/xa+cv/Attic/Makefile,v 1.1.1.1 1999-09-09 10:11:51 foxfair Exp $
#

DISTNAME=	xa+cv-0.6
PKGNAME=	zh-xa+cv-0.6
CATEGORIES=	chinese
MASTER_SITES=	ftp://linux.tmtc.edu.tw/pub/CLE/devel/source/tarball/

MAINTAINER=	clive@CirX.ORG

RUN_DEPENDS=	${X11BASE}/bin/xcin:${PORTSDIR}/chinese/xcin \
		${X11BASE}/lib/X11/fonts/TrueType/moe_sung.ttf:${PORTSDIR}/chinese/moettf

USE_GMAKE=	yes

DOC1=		FAQ NEW README.XA README.+CV README.XA+CV-0.5 USE.Big5 USE.GB
EX1=		README cnetscape cxcoral cxemacs cxterm dot.fvwm2rc95 et24 \
		et24r ns

post-install:
	@${ECHO} "========================================================="
	@${ECHO} "-=> Install examples to invoke XA+CV"
	@${ECHO} "    into ${PREFIX}/share/examples/xa+cv"
	@${ECHO} " "
	@${MKDIR} ${PREFIX}/share/examples/xa+cv
.for i in ${EX1}
	@${INSTALL_DATA} ${WRKSRC}/example/${i} ${PREFIX}/share/examples/xa+cv/${i}
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO} "-=> Install documents into ${PREFIX}/share/doc/xa+cv"
	@${ECHO} " "
	@${MKDIR} ${PREFIX}/share/doc/xa+cv
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/xa+cv/${i}
.endfor
.endif
	@${ECHO} "-=> Done."
	@${ECHO} " "
	@${ECHO} "If you are inpatient, simply set environment varible
	@${ECHO} "LD_PRELOAD = ${PREFIX}/lib/wrap.so to make it work."
	@${ECHO} " "
	@${ECHO} "========================================================="

.include <bsd.port.mk>
