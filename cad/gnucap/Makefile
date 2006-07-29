# ex:ts=8
# Ports collection makefile for:	gnucap
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnucap
PORTVERSION=	2006.07.08
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.geda.seul.org/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	The Gnu Circuit Analysis Package

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PORTNAME} \
			--mandir=${PREFIX}/man

OPTIONS=	READLINE "Enable commandline features via readline" on

MAN1=		gnucap.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_READLINE) || exists(${LOCALBASE}/lib/libreadline.so.5)
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

.include <bsd.port.post.mk>
