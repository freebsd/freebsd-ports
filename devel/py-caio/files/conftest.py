import pytest
import caio


@pytest.fixture
def context_maker():
    """Create caio.Context instances"""
    def maker(max_events=0):
        return caio.Context(max_events)
    return maker


@pytest.fixture
def async_context_maker():
    """Create async caio.AsyncioContext instances"""
    def maker(max_events=0):
        return caio.AsyncioContext(max_events)
    return maker


@pytest.fixture
def asyncio_exception_handler():
    """Handle asyncio exceptions"""
    exceptions = []
    
    def handler(loop, context):
        exceptions.append(context)
    
    return handler
