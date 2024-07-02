PORTNAME=	spsdk
DISTVERSION=	2.2.1
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	awoonyaa@gmail.com
COMMENT=	Connection and data exchange with devices for secure configuration and programming
WWW=		https://pypi.org/project/spsdk/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.2,<1.6:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bincopy>=17.14.5,<17.15:converters/py-bincopy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bitstring>=3.1:devel/py-bitstring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.1,<8.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-plugins>0:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-option-group>=0.3.0,<0.6:devel/py-click-option-group@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-command-tree<1.2:devel/py-click-command-tree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}commentjson>=0.9,<0.10:devel/py-commentjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crcmod<1.8:devel/py-crcmod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepmerge<1.2:devel/py-deepmerge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastjsonschema>=2.15.1:devel/py-fastjsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hexdump<3.4:textproc/py-hexdump@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libusbsio>=2.1.11,<2.2:comms/py-libusbsio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oscrypto<1.4:security/py-oscrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.9.3:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylink-square>=1.0,<=1.2:comms/py-pylink-square@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyocd>=0.35.1,<=0.36:comms/py-pyocd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypemicro>=0.1.11,<0.2:devel/py-pypemicro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyocd-pemicro>=1.1.5,<1.2:comms/py-pyocd-pemicro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.1,<3.6:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sly>0:lang/py-sly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions<=5.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=1.5.1:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.2.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=0:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.2,<1.6:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bincopy>=17.14.5,<17.15:converters/py-bincopy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bitstring>=3.1:devel/py-bitstring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.1,<8.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-plugins>0:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-option-group>=0.3.0,<0.6:devel/py-click-option-group@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-command-tree<1.2:devel/py-click-command-tree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}commentjson>=0.9,<0.10:devel/py-commentjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crcmod<1.8:devel/py-crcmod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepmerge<1.2:devel/py-deepmerge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastjsonschema>=2.15.1:devel/py-fastjsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hexdump<3.4:textproc/py-hexdump@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libusbsio>=2.1.11,<2.2:comms/py-libusbsio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oscrypto<1.4:security/py-oscrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.9.3:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylink-square>=1.0,<=1.2:comms/py-pylink-square@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyocd>=0.35.1,<=0.36:comms/py-pyocd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypemicro>=0.1.11,<0.2:devel/py-pypemicro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyocd-pemicro>=1.1.5,<1.2:comms/py-pyocd-pemicro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.1,<3.6:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sly>0:lang/py-sly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions<=5.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=1.5.1:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.2.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
