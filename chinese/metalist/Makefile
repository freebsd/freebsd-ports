# New ports collection makefile for:	metalist
# Date created:				18 March 2002
# Whom:					Autrijus Tang
#
# $FreeBSD$
#

PORTNAME=	metalist
PORTVERSION=	2.2.6
PORTREVISION=	11069
CATEGORIES=	chinese www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	slashcode
DISTNAME=	slash-${PORTVERSION}

PATCH_SITES=	http://p4.elixus.org/hist/
PATCHFILES=	metalist-${PORTREVISION}${EXTRACT_SUFX}

MAINTAINER=	autrijus@autrijus.org
COMMENT=	A Chinese port of Slash-Like Automatic Storytelling Homepage system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/Bundle/Slash.pm:${PORTSDIR}/www/p5-Bundle-Slash \
		${SITE_PERL}/Locale/Maketext/Lexicon.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		${SITE_PERL}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

.if defined(WITH_OURNET)
CONFIGURE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--default
MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--default
.else
CONFIGURE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip
MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip
.endif

.if defined(WITH_APACHE2)
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache2/mod_perl.so:${PORTSDIR}/www/mod_perl2
DEPENDS_ARGS+=	WITHOUT_MODPERL=yes
DEPENDS_ARGS+=	WITH_MODPERL2=yes
DEPENDS_ARGS+=	WITH_APACHE2=yes
DEPENDS_ARGS+=	BATCH=yes
.else
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl
.endif

DOCS=		README README.metalist INSTALL
NO_BUILD=	yes

CONFLICTS=	slash

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		FZ.3 Slash.3 Slash::Apache.3 Slash::Apache::Banlist.3 \
		Slash::Apache::Log.3 Slash::Apache::User.3 \
		Slash::Custom::Bulkmail.3 Slash::DB.3 Slash::DB::MySQL.3 \
		Slash::DB::Oracle.3 Slash::DB::PostgreSQL.3 \
		Slash::DB::Static::MySQL.3 Slash::DB::Static::Oracle.3 \
		Slash::DB::Static::PostgreSQL.3 Slash::DB::Utility.3 \
		Slash::Display.3 Slash::Display::Plugin.3 \
		Slash::Display::Provider.3 Slash::Install.3 Slash::Journal.3 \
		Slash::Messages.3 Slash::Messages::DB::MySQL.3 \
		Slash::Search.3 Slash::Test.3 Slash::Utility.3 \
		Slash::Utility::Access.3 Slash::Utility::Anchor.3 \
		Slash::Utility::Data.3 Slash::Utility::Display.3 \
		Slash::Utility::Environment.3 Slash::Utility::System.3 \
		Slash::XML.3 Slash::XML::RSS.3

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_APACHE2                    Use Apache2 as the web server"
	@${ECHO} "      WITH_OURNET                     Install support for OurNet::BBS"
	@${ECHO} ""

do-patch:
	@${MV} ${WRKSRC} ${WRKDIR}/src
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${PATCHFILES} ${EXTRACT_AFTER_ARGS})
	@${MV} ${WRKDIR}/src ${WRKSRC}
	@(cd ${WRKSRC} && ${PATCH} < ${MASTERDIR}/files/patch-Makefile 2>/dev/null)
.if defined(WITH_APACHE2)
	@(cd ${WRKDIR} && ${PATCH} < ${WRKSRC}/slash-2.2.6-modperl2.diff.txt 2>/dev/null)
.endif

post-install:
	@${FIND} ${PREFIX}/slash -name "*.orig" -delete
.if defined(WITH_APACHE2)
	@${SED} -e s!%%LOCALBASE%%!${LOCALBASE}!g -e s!%%APACHE%%!apache2!g ${PKGMESSAGE}
.else
	@${SED} -e s!%%LOCALBASE%%!${LOCALBASE}!g -e s!%%APACHE%%!apache!g ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This program only support perl 5.6.1 or above
.endif

.include <bsd.port.post.mk>
