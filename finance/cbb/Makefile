# Created by: kline
# $FreeBSD$

PORTNAME=	cbb
DISTVERSION=	0.9.5b
CATEGORIES=	finance deskutils
MASTER_SITES=	http://download.gna.org/cbb/

MAINTAINER=	kline@thought.org
COMMENT=	Checkbook balancing tool

BROKEN=		unfetchable

LICENSE=	GPLv2

NO_BUILD=	yes
USES=		shebangfix perl5 tk tar:tgz
SHEBANG_FILES=	tcl/*.tcl */*.pl contrib/*
SHEBANG_LANG=	perl tk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-perl=${PERL} \
		--with-wish=${WISH}
MAKE_ENV+=	STAGEDIR=${STAGEDIR}
WRKSRC=		${WRKDIR}/${PKGNAME:R}
PLIST_SUB+=	VERSION=${PORTVERSION:R:R}

post-patch:
	${REINPLACE_CMD}  -e 's|.aboutwin.frame.a.l6 ||' \
	    ${WRKSRC}/tcl/help.tcl
	${REINPLACE_CMD}  -e 's|%4Y%02m%02d|%Y%m%d|' \
	    ${WRKSRC}/tcl/main.tcl
	${REINPLACE_CMD} -e 's|/usr/bin/perl|${TCLSH}|' \
	    ${WRKSRC}/languages/*.tcl

.include <bsd.port.mk>
