# New ports collection makefile for:	jyuroku
# Date created:		1 February 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	jyuroku
PORTVERSION=	1.32
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://homepage3.nifty.com/seto-yoneji/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	Japanese address book

ALL_TARGET=
USE_X_PREFIX=	yes
USE_GNOME=	gtk12

post-patch:
	${REINPLACE_CMD} -e "s@gcc@${CC}@g; \
			s@-g@${CFLAGS}@g; \
			s@gtk-config@${GTK_CONFIG}@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jyuroku ${X11BASE}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jyuroku
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/jyuroku
.endif

.include <bsd.port.mk>
