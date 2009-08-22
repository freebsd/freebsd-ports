# New ports collection makefile for:	joe
# Date created:		01 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	joe
PORTVERSION=	3.7
PORTEPOCH=	1
CATEGORIES+=	editors
MASTER_SITES=	SF/joe-editor/JOE%20sources/joe-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER?=	chinsan@FreeBSD.org
COMMENT=	Joe's Own Editor

BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

CONFLICTS=	joe-2.*

USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -liconv"

ALL_TARGET=	${PORTNAME}
MAN1=		${PORTNAME}.1

MANLANG=	"" ru

.include <bsd.port.pre.mk>

.ifdef NOPORTDOCS
post-patch:
	${REINPLACE_CMD} 's,install-data-am: install-data_charmapsDATA install-data_docDATA,install-data-am: install-data_charmapsDATA,' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.for file in jmacsrc jpicorc jstarrc rjoerc joerc
.if !exists(${PREFIX}/etc/${PORTNAME}/${file})
	@${CP} ${PREFIX}/etc/${PORTNAME}/${file} ${PREFIX}/etc/${PORTNAME}/${file}.dist
.endif
.endfor

.include <bsd.port.post.mk>
