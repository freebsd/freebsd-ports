# New ports collection makefile for:	virt
# Date created:			8 May 2001
# Whom:				lg
#
# $FreeBSD$

PORTNAME=	virt
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://vampiro.rshb.com.ru/pub/warez/virt/ \
		ftp://ftp.treasury.ru/pub/unix/virt/

MAINTAINER=	lg@rrf.ru
COMMENT=	Game and keyboard teacher in one. Enjoy it!

USE_GNOME=	gtk12
USE_PERL5_BUILD=yes
MAN6=		virt.6
MANCOMPRESSED=	no

post-patch:
	@${PERL} -pi -e "s,gtk-config,${GTK_CONFIG},g ; \
		s,%%INSTALL_PROGRAM%%,${INSTALL_PROGRAM},g ; \
		s,%%INSTALL_DATA%%,${INSTALL_DATA},g ; \
		s,%%INSTALL_MAN%%,${INSTALL_MAN},g" ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/keytop

.include <bsd.port.mk>
