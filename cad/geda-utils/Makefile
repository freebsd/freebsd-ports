# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	utils
PORTVERSION=	1.4.3
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The gEDA's utilities

RUN_DEPENDS=	${LOCALBASE}/share/geda/sym:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	geda.33:${PORTSDIR}/cad/libgeda

DOCSDIR=	${PREFIX}/share/doc/geda
DATADIR=	${PREFIX}/share/geda

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_PERL5_RUN=	yes
USE_PYTHON_RUN=	yes
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		grenum.1

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(DATADIR[[:space:]]*=[[:space:]]*)gEDA,\1geda," \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E \
		-e "s,^(#!)/usr/bin/perl,\1${PERL}," \
		-e "s,^(#!)/usr/bin/python,\1${PYTHON_CMD}," \
		${WRKSRC}/scripts/*

.include <bsd.port.mk>
