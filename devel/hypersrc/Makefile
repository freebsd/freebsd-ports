# ex:ts=8
# New ports collection makefile for:	hypersrc
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hypersrc
PORTVERSION=	4.4.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimbrooks.org/hypersrc/latest/

MAINTAINER=	ijliao@FreeBSD.org

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

USE_BISON=	yes
USE_GTK=	yes
USE_GNOME=	yes

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${PERL} -pi -e "s,/usr/local,${PREFIX},g ;\
		s,gtk-config,${GTK_CONFIG},g ; \
		s,gnome-config,${GNOME_CONFIG},g" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s,/usr/bin/ctags,${LOCALBASE}/bin/exctags,g" ${WRKSRC}/Hypersrc.pl

.include <bsd.port.mk>
