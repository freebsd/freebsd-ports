# Created by: bruno schwander <bruno@tinkerbox.org>
# $FreeBSD$

PORTNAME=	utils
PORTVERSION=	1.4.3
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The gEDA's utilities

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
RUN_DEPENDS=	geda-symbols>0:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	libgeda.so:${PORTSDIR}/cad/libgeda

DOCSDIR=	${PREFIX}/share/doc/geda
DATADIR=	${PREFIX}/share/geda

USES=		gmake perl5 pkgconfig python:run shebangfix
SHEBANG_FILES=	scripts/gnet_hier_verilog.sh
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_PERL5=	run
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(DATADIR[[:space:]]*=[[:space:]]*)gEDA,\1geda," \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E \
		-e "s,^(#!)/usr/bin/perl,\1${PERL}," \
		-e "s,^(#!)/usr/bin/python,\1${PYTHON_CMD}," \
		${WRKSRC}/scripts/*

.include <bsd.port.mk>
