# New ports collection makefile for:    p5-DBD-ODBC
# Date created:				Nov 30 2001
# Whom:	      				Clive Lin <clive@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-ODBC
PORTVERSION=	1.13
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DBD module interfacing the ODBC databases

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	-o ${LOCALBASE}
USE_REINPLACE=	yes

MAN3=		DBD::ODBC.3

OPTIONS=	IODBC "Link with libiodbc" on \
		ODBC "Link with unixODBC (Only with 5.x+)" off

.include <bsd.port.pre.mk>

.if defined(WITH_IODBC) && defined(WITH_ODBC)
BROKEN=	"Should only select one of ODBC and IODBC"
.endif
.if defined(WITH_ODBC) && ${OSVERSION} < 500016
IGNORE=	Due to some obscure -pthread things, you can not have this work
.endif

.if !defined(WITHOUT_IODBC)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
MYODBC=	iodbc
.endif
.if defined(WITH_ODBC)
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
MYODBC=	unixodbc
post-configure:
	@${PERL} -pi -e 's/-lodbc/-lodbc ${PTHREAD_LIBS}/g;' \
		-e 's/$$/ ${PTHREAD_CFLAGS}/ if (/^CCFLAGS/);' \
		${WRKSRC}/Makefile
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README README.adabas README.informix

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/[[:<:]]our[[:>:]]/my/g' \
			  -e 's/^    @$$(NOOP)/	@$$(NOOP)/g' ${WRKSRC}/Makefile.PL
	@${PERL} -pi -e '$$_ .= "\$$myodbc = \"${MYODBC}\";" if ($$. == 204);' \
		${WRKSRC}/Makefile.PL

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
