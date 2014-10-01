# $FreeBSD$
#
# Provide support for Twisted-related ports
#
# Feature:		twisted
# Usage:		USES=	twisted:build,run,compA,compB,...
# Valid ARGS:
#				build	Adds twisted and any additional component as build
#						dependency to the port
#				run	Adds twisted and any additional component as run
#						dependency to the port
#				comp	Adds the specified twisted component to as build or
#						run dependency to the ports
#
# If the build and run arguments are omitted, twisted or any specified
# component will be added as build AND run dependency.
#
# The current supported components are:
#
#	conch flow lore mail names news runner web web2 words
#
# MAINTAINER: python@FreeBSD.org

.if !defined(_INCLUDE_USES_TWISTED_MK)
_INCLUDE_USES_TWISTED_MK=	yes

# If neither build nor run are specified add both.
.if ${twisted_ARGS:Mbuild} || empty(twisted_ARGS:Mrun)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twistedCore
.endif
.if ${twisted_ARGS:Mrun} || empty(twisted_ARGS:Mbuild)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twistedCore
.endif

_TWISTED_COMPONENTS=	conch flow lore mail names news pair runner web web2 words

conch_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/conch/__init__.py:${PORTSDIR}/security/py-twistedConch
flow_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/flow/__init__.py:${PORTSDIR}/devel/py-twistedFlow
lore_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/lore/__init__.py:${PORTSDIR}/textproc/py-twistedLore
mail_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/mail/__init__.py:${PORTSDIR}/mail/py-twistedMail
names_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/names/__init__.py:${PORTSDIR}/dns/py-twistedNames
news_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/news/__init__.py:${PORTSDIR}/news/py-twistedNews
pair_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/pair/__init__.py:${PORTSDIR}/net/py-twistedPair
runner_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/runner/__init__.py:${PORTSDIR}/devel/py-twistedRunner
web2_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/web2/__init__.py:${PORTSDIR}/www/py-twistedWeb2
web_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb
words_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/words/__init__.py:${PORTSDIR}/net-im/py-twistedWords

.for component in ${twisted_ARGS:Nbuild:Nrun}
.  if ${_TWISTED_COMPONENTS:M${component}}==""
IGNORE=	cannot install unknown twisted component ${component}
.  endif
# If neither build nor run are specified add both.
.  if ${twisted_ARGS:Mbuild} || empty(twisted_ARGS:Mrun)
BUILD_DEPENDS+=	${${component}_DEPENDS}
.  endif
.  if ${twisted_ARGS:Mrun} || empty(twisted_ARGS:Mbuild)
RUN_DEPENDS+=	${${component}_DEPENDS}
.  endif
.endfor

.endif # !defined(_INCLUDE_USES_TWISTED_MK)
