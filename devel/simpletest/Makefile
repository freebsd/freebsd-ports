# Ports collection makefile for:  simpletest
# Date created:			  16 August 2004
# Whom:				  Roman Neuhauser (<neuhauser@chello.cz>)
#
# $FreeBSD$
#

PORTNAME=	SimpleTest
PORTVERSION=	1.0.r1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}/
DISTNAME=	php_simple_test_1.0RC1

MAINTAINER=	neuhauser@chello.cz
COMMENT=	Unit testing, mock objects and web testing framework for PHP

USE_PHP=	pcre
USE_PHP_BUILD=	yes
NO_BUILD=	yes

SIMPLETESTS?=	unit

.include <bsd.port.pre.mk>

PHP_CONFIG?=	${LOCALBASE}/bin/php-config

.if !defined(PEARDIR) && exists(${PHP_CONFIG})
_PEARPREFIX!=	${PHP_CONFIG} --prefix
_PEARDIR=	share/pear
PEARDIR=	${_PEARPREFIX}/${_PEARDIR}
.endif
WRKSRC=		${WRKDIR}/${PORTNAME:L}
PLIST_SUB+=	PEARDIR="${_PEARDIR}"
.if !defined(NOPORTDOCS)
DOCS=		HELP_MY_TESTS_DONT_WORK_ANYMORE LICENSE README VERSION \
		docs/expectation_documentation.html \
		docs/form_testing_documentation.html \
		docs/group_test_documentation.html \
		docs/index.html \
		docs/mock_objects_documentation.html \
		docs/overview.html \
		docs/partial_mocks_documentation.html \
		docs/reporter_documentation.html \
		docs/server_stubs_documentation.html \
		docs/unit_test_documentation.html \
		docs/web_tester_documentation.html
.endif

TESTS=		test/acceptance_test.php \
		test/adapter_test.php \
		test/all_tests.php \
		test/authentication_test.php \
		test/browser_test.php \
		test/dumper_test.php \
		test/errors_test.php \
		test/expectation_test.php \
		test/form_test.php \
		test/frames_test.php \
		test/http_test.php \
		test/live_test.php \
		test/options_test.php \
		test/page_test.php \
		test/parser_test.php \
		test/real_sites_test.php \
		test/remote_test.php \
		test/shell_test.php \
		test/shell_tester_test.php \
		test/simple_mock_test.php \
		test/socket_test.php \
		test/tag_test.php \
		test/unit_tests.php \
		test/url_test.php \
		test/user_agent_test.php \
		test/visual_test.php \
		test/web_tester_test.php \
		test/xml_test.php

CLASSES=	authentication.php browser.php dumper.php errors.php \
		expectation.php extensions/pear_test_case.php \
		extensions/phpunit_test_case.php form.php frames.php http.php \
		mock_objects.php options.php page.php parser.php remote.php \
		reporter.php scorer.php shell_tester.php simple_test.php \
		socket.php tag.php unit_tester.php url.php user_agent.php \
		web_tester.php xml.php

pre-patch:
	${CP} -r ${WRKSRC}/test ${WRKSRC}/test.beforeinstall

#do-build:
#	cd ${WRKSRC}/test.beforeinstall && \
#	${LOCALBASE}/bin/php -f ${SIMPLETESTS}_tests.php

do-install:
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	${MKDIR} ${DATADIR}/test
.for f in ${TESTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}/${f}
.endfor
	${MKDIR} ${PEARDIR}/simpletest/extensions
.for f in ${CLASSES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PEARDIR}/simpletest/${f}
.endfor

.include <bsd.port.post.mk>
