# ex:ts=8
# Ports collection makefile for:	gnucap
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnucap
PORTVERSION=	2008.06.08
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.gnucap.org/devel/archive/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNU Circuit Analysis Package

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PORTNAME}

OPTIONS=	READLINE "Enable commandline features via readline" on

MAN1=		gnucap.1 gnucap-ibis.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_READLINE) || exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.include <bsd.port.post.mk>
