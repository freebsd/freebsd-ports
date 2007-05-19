# New ports collection makefile for: wyrd
# Date created:                      Apr 5 2006
# Whom:                              Russell A. Jackson <raj@csub.edu>
#
# $FreeBSD$
#

PORTNAME=	wyrd
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/wyrd/

MAINTAINER=	raj@csub.edu
COMMENT=	A curses front end to remind

BUILD_DEPENDS=	${LOCALBASE}/bin/ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	${LOCALBASE}/bin/remind:${PORTSDIR}/deskutils/remind

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		wyrd.1
MAN5=		wyrdrc.5
PLIST_FILES=	bin/wyrd etc/wyrdrc

.include <bsd.port.mk>
