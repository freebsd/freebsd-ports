# New ports collection makefile for:	automake
# Date created:		15 March 1997
# Whom:			FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	automake14
PORTVERSION=	1.4.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake
DISTNAME=	automake-1.4-p5

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL5}
CONFIGURE_ARGS=	--program-suffix=14 --datadir=${PREFIX}/share/automake14
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

STRIP=		# none

.if defined(USE_AUTOMAKE) || defined(USE_AUTOMAKE_VER)
.error You have `USE_AUTOMAKE' or `USE_AUTOMAKE_VER' variables defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

post-patch:
	@-${RM} ${WRKSRC}/*.info* ${WRKSRC}/*.dvi
	${MV} ${WRKSRC}/automake.texi ${WRKSRC}/automake14.texi

pre-configure:
	${PERL} -pi -e "s^%%X11BASE%%^${X11BASE}^" ${WRKSRC}/aclocal.in

post-install:
	@-${RM} -fr ${PREFIX}/libexec/automake14
	@${MKDIR} ${PREFIX}/libexec/automake14
.for i in aclocal automake
	@${LN} -s ../../bin/${i}14 ${PREFIX}/libexec/automake14/${i}
.endfor
	@install-info ${PREFIX}/info/automake14.info ${PREFIX}/info/dir

.include <bsd.port.mk>
