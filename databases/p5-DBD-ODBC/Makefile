# New ports collection makefile for:    p5-DBD-ODBC
# Date created:				Nov 30 2001
# Whom:	      				Clive Lin <clive@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-ODBC
PORTVERSION=	1.06
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DBD module interfacing the ODBC databases

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	iodbc.3:${PORTSDIR}/databases/libiodbc
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	-o ${LOCALBASE}

MAN3=		DBD::ODBC.3

post-patch:
	@${REINPLACE_CMD} -e 's/[[:<:]]our[[:>:]]/my/g' \
			  -e 's/^    @$$(NOOP)/	@$$(NOOP)/g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
