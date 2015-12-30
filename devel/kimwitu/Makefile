# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kimwitu
PORTVERSION=	4.6.1
CATEGORIES=	devel
MASTER_SITES=	http://fmt.cs.utwente.nl/kimwitu/ftp/ \
		http://www.sourcefiles.org/Programming/Compilers/Object-Oriented/
DISTNAME=	kc-distr.V${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for processing trees (i.e. terms)

WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/kc man/man1/kc.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Gen/kc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../man/kc.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
