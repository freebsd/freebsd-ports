# New ports collection makefile for:	oxford
# Date created:		30 Dec 2002
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	oxford
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	ftp://igloo.its.unimelb.edu.au/pub/Oxford_Dictionary/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/oxford/
DISTFILES=	a.zip b.zip c.zip d.zip e.zip f.zip g.zip h.zip i.zip \
		j.zip k.zip l.zip m.zip n.zip o.zip p.zip q.zip r.zip \
		s.zip t.zip u.zip v.zip w.zip x.zip y.zip z.zip \
		oxford-0.2.el.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A English to Chinese(GB) dictionary

DIST_SUBDIR=	oxford
USE_ZIP=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/oxford
	${INSTALL_DATA} ${WRKDIR}/*.dic ${PREFIX}/share/oxford
	${INSTALL_DATA} ${WRKDIR}/*.el ${PREFIX}/share/oxford
	${MKDIR} ${PREFIX}/bin
	${INSTALL} ${FILESDIR}/oxford ${PREFIX}/bin

.include <bsd.port.mk>
