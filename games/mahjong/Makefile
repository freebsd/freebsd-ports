# ex:ts=8
# New ports collection makefile for:   mahjong
# Date created:                Jan 31, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mahjong
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	games net
MASTER_SITES=	http://www.stevens-bradfield.com/MahJong/Source/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD
DISTNAME=	mj-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A networked Mah Jong program, together with a computer player

USE_PERL5_BUILD=	yes
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

do-install:
.for file in mj-server mj-player xmj
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin/${file}
.endfor
	${INSTALL_MAN} ${WRKSRC}/xmj.man ${MANPREFIX}/man/man1/xmj.1

.include <bsd.port.mk>
