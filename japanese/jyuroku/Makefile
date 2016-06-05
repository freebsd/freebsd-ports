# Created by: Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	jyuroku
PORTVERSION=	1.32
PORTREVISION=	7
CATEGORIES=	japanese
MASTER_SITES=	http://homepage3.nifty.com/seto-yoneji/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese address book

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

ALL_TARGET=
USE_GNOME=	gtk12

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s@gcc@${CC}@g; \
			s@-g@${CFLAGS}@g; \
			s@gtk-config@${GTK_CONFIG}@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jyuroku ${STAGEDIR}${LOCALBASE}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
