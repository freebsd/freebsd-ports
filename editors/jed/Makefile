# New ports collection makefile for:    Jed text editor
# Date created:         22 APR 1997
# Whom:                 eric
#
# $FreeBSD$
#

PORTNAME=	jed
PORTVERSION=	0.99.15
CATEGORIES=	editors
MASTER_SITES=	ftp://space.mit.edu/pub/davis/jed/v${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-B${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	s_bschmi@ira.uka.de

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang


.if !defined(WITHOUT_X11)
USE_XLIB=	yes
XJED=	xjed
PLIST_SUB+=  	NOXJED=""
.else
PLIST_SUB+=		NOXJED="@comment "
.endif

DIST_SUBDIR=	jed
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	JED_ROOT=${PREFIX}/lib/jed
ALL_TARGET=	all getmail ${XJED}
MAN1=		jed.1 rgrep.1

pre-install:
	${LN} -sf ${WRKSRC}/autoconf/mkinsdir.sh  ${WRKSRC}/

post-install:
	strip ${PREFIX}/bin/jed
	strip ${PREFIX}/bin/rgrep
	strip ${PREFIX}/lib/jed/bin/getmail
.for f in ${XJED}
	strip ${PREFIX}/bin/$f
.endfor
	${CP} -R ${WRKSRC}/lib/* ${PREFIX}/lib/jed/lib
	-${RM} ${PREFIX}/lib/jed/info/*
	-${RMDIR} ${PREFIX}/lib/jed/info
	-${RM} ${PREFIX}/lib/jed/doc/txt/*
	-${RMDIR} ${PREFIX}/lib/jed/doc/txt
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jed
	${INSTALL_DATA} ${WRKSRC}/doc/txt/*.txt \
		${PREFIX}/share/doc/jed
	${INSTALL_DATA} ${WRKSRC}/info/jed.* ${PREFIX}/info
	install-info --section="Miscellaneous" \
		--entry="* JED: (jed).			JED editor documentation." \
		${PREFIX}/info/jed.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
