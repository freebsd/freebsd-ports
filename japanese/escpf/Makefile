# New ports collection makefile for: escpf
# Date created:		15 June 1996
# Whom:			Mita Yoshio <mita@iis.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	escpf
PORTVERSION=	0.4
CATEGORIES=	japanese print
MASTER_SITES=	http://www.flatout.org/~wing/Linux/Escpf/

MAINTAINER=	mita@jp.FreeBSD.org
COMMENT=	Text filters for ESC/P, ESC/Page and ESC/PS printers

DOCDIR=		${PREFIX}/share/doc/escpf
LINES?=		66
COLUMNS?=	80
TOP_MERGIN?=	5
LEFT_MERGIN?=	5
LARGE_FONT?=	-DLARGE_FONT
MAKE_ENV+=	LINES=${LINES} COLUMNS=${COLUMNS} \
		TOP_MERGIN=${TOP_MERGIN} LEFT_MERGIN=${LEFT_MERGIN} \
		LARGE_FONT="${LARGE_FONT}"
# You can specify page layout with:
#       LINES           : lines per page
#       COLUMNS         : characters per line
#       TOP_MERGIN      : top mergin with lines
#       LEFT_MERGIN     : left mergin with cahacters
#       LARGE_FONT      : if "-DLARGE_FONT" large font, "" small font

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/escpf.doc ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/escpf.euc ${DOCDIR}
.endif

.include <bsd.port.mk>
