# ex:ts=8
# New ports collection makefile for:	lfhex
# Date created:			Jul 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lfhex
PORTVERSION=	0.3.2
CATEGORIES=	editors
MASTER_SITES=	ftp://typedef.dnsalias.org/pub/lfhex/

MAINTAINER=	kde@freebsd.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_QT_VER=	2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-moc=${MOC}
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g ; \
		s,%%X11BASE%%,${X11BASE},g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
