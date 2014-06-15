# Created by: Sergei Vyshenski
# $FreeBSD$

PORTNAME=	Workflow
PORTVERSION=	1.40
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Simple, flexible system to implement workflows

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Class-Observable>=1.04:${PORTSDIR}/devel/p5-Class-Observable \
		p5-Class-Accessor>=0.18:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBD-Mock>=0.1:${PORTSDIR}/databases/p5-DBD-Mock \
		p5-Class-Factory>=1:${PORTSDIR}/devel/p5-Class-Factory \
		p5-DateTime>=0.15:${PORTSDIR}/devel/p5-DateTime \
		p5-Exception-Class>=1.1:${PORTSDIR}/devel/p5-Exception-Class \
		p5-DateTime-Format-Strptime>=1:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-XML-Simple>=2:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Log-Dispatch>=2:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=0.34:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Data-UUID>=0:${PORTSDIR}/devel/p5-Data-UUID \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
BUILD_DEPENDS=	p5-Class-Observable>=1.04:${PORTSDIR}/devel/p5-Class-Observable \
		p5-Class-Accessor>=0.18:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBD-Mock>=0.1:${PORTSDIR}/databases/p5-DBD-Mock \
		p5-Class-Factory>=1:${PORTSDIR}/devel/p5-Class-Factory \
		p5-DateTime>=0.15:${PORTSDIR}/devel/p5-DateTime \
		p5-Exception-Class>=1.1:${PORTSDIR}/devel/p5-Exception-Class \
		p5-DateTime-Format-Strptime>=1:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-XML-Simple>=2:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Log-Dispatch>=2:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=0.34:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Data-UUID>=0:${PORTSDIR}/devel/p5-Data-UUID \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

PORTEXAMPLES=	*
PORTDOCS=	*

.if ${PORT_OPTIONS:MDATA}
PORTDATA=	*
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/eg && ${COPYTREE_SHARE} ticket/\* ${STAGEDIR}${EXAMPLESDIR}/)
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.if ${PORT_OPTIONS:MDATA}
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} struct/\* ${DATADIR}/)
	@${ECHO_MSG} "===> SQL data structures installed in ${DATADIR}."
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/ && ${CP} -R README Changes TODO doc ${STAGEDIR}${DOCSDIR}/)
	@${ECHO_MSG} "===> Docs are installed in ${DOCSDIR}."

.include <bsd.port.mk>
