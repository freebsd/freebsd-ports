# ex:ts=8
# New ports collection makefile for:   mahjong
# Date created:                Jan 31, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mahjong
PORTVERSION=	1.4.1
CATEGORIES=	games net
MASTER_SITES=	http://www.stevens-bradfield.com/MahJong/Source/ \
		http://www.stevens-bradfield.com/MahJong/Source/Old/
DISTNAME=	mj-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
MAKE_ENV=	CCLINK="${CC}" CDEBUGFLAGS="${CFLAGS}" \
		DESTDIR="${PREFIX}/" INSTMANFLAGS="${INSTALL_MAN}" \
		INSTPGMFLAGS="${INSTALL_PROGRAM}" PERL="${PERL}"
INSTALL_TARGET=	install install.man

MAN1=		xmj.1
MLINKS=		xmj.1 mj-player.1 \
		xmj.1 mj-server.1

post-patch:
	@${PERL} -pi -e 's|^CC|#CC|g ; \
		 s|^DESTDIR|#DESTDIR|g ; \
		 s|^CDEBUGFLAGS|#CDEBUGFLAGS|g ; \
		 s|^MAKE|#MAKE|g ; \
		 s|^PERL|#PERL|g ; \
		 s|^INST|#INST|g ; \
		 s|gtk-config|\$$\{GTK_CONFIG\}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
