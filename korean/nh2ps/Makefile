# New ports collection makefile for:    nh2ps-2.3
# Date created:         2 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	nh2ps
PORTVERSION=	2.3.1
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/users/cjh/nh2ps/

MAINTAINER=	cjh@FreeBSD.org

MAN1=		nh2ps.1

post-patch:
	@(cd ${WRKSRC}; \
	  ${SED} s@/usr/local/bin/perl@${PERL5}@ mkpsfontmap.pl > mk.pl; \
	  ${MV} -f mk.pl mkpsfontmap.pl; \
	  ${CHMOD} +x mkpsfontmap.pl)

pre-install:
	@(cd ${WRKSRC}; make install.man)

post-install:
	strip ${PREFIX}/bin/nh2ps
	@${MKDIR} ${PREFIX}/share/doc/nh2ps
	${INSTALL_DATA} ${WRKSRC}/README.nh2ps ${PREFIX}/share/doc/nh2ps/
	${INSTALL_DATA} ${WRKSRC}/README.font ${PREFIX}/share/doc/nh2ps/
	${INSTALL_DATA} ${WRKSRC}/README.filtering_with_gs \
		${PREFIX}/share/doc/nh2ps/

.include <bsd.port.mk>
